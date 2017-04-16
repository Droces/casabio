<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Samsung;

use PHPExiftool\Driver\AbstractTag;

class Quality extends AbstractTag
{

    protected $Id = 'QLTY';

    protected $Name = 'Quality';

    protected $FullName = 'Samsung::INFO';

    protected $GroupName = 'Samsung';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Samsung';

    protected $g2 = 'Video';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Quality';

    protected $flag_Permanent = true;

}