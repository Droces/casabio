<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Olympus;

use PHPExiftool\Driver\AbstractTag;

class ISOValue extends AbstractTag
{

    protected $Id = 4097;

    protected $Name = 'ISOValue';

    protected $FullName = 'Olympus::Main';

    protected $GroupName = 'Olympus';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Olympus';

    protected $g2 = 'Camera';

    protected $Type = 'rational64s';

    protected $Writable = true;

    protected $Description = 'ISO Value';

    protected $flag_Permanent = true;

}
