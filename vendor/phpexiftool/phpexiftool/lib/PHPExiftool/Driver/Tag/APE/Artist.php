<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\APE;

use PHPExiftool\Driver\AbstractTag;

class Artist extends AbstractTag
{

    protected $Id = 'Artist';

    protected $Name = 'Artist';

    protected $FullName = 'APE::Main';

    protected $GroupName = 'APE';

    protected $g0 = 'APE';

    protected $g1 = 'APE';

    protected $g2 = 'Audio';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Artist';

}