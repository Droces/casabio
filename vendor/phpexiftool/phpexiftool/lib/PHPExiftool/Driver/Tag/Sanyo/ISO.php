<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Sanyo;

use PHPExiftool\Driver\AbstractTag;

class ISO extends AbstractTag
{

    protected $Id = 106;

    protected $Name = 'ISO';

    protected $FullName = 'Sanyo::MP4';

    protected $GroupName = 'Sanyo';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Sanyo';

    protected $g2 = 'Camera';

    protected $Type = 'int32u';

    protected $Writable = false;

    protected $Description = 'ISO';

    protected $flag_Permanent = true;

}